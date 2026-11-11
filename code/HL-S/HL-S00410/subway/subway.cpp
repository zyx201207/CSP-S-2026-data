// SPDX-License-Identifier: MPL-2.0
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
int enter_times[500000];
int pass_count[500000];
int plan_start[100000],plan_end[100000];
typedef struct{
    int station_count;
    int* stations_index;
    int* stations_exit_time;
}MetroLine;
MetroLine metor_line[250];
int use_count[250];
int switch_time[250][250];
int switch_point[250][250];
int first_own[500000];
int min_disten_calc(int start,int end_st,int n,int m){
    int own=first_own[start],dst=999999999;
    if(first_own[end_st]==own)return enter_times[start]+enter_times[end_st];
    if(switch_time[own][first_own[end_st]]){
        if(switch_point[own][first_own[end_st]]==start){
            return enter_times[start]+enter_times[end_st];
        }
        return enter_times[start]+enter_times[end_st]+switch_time[own][first_own[end_st]];
    }
    for(int i=0;i<n;i++){
        if(switch_time[i][own]&&switch_time[i][first_own[end_st]])return switch_time[i][own]+switch_time[i][first_own[end_st]]+enter_times[start]+enter_times[end_st];
    }
    return enter_times[start]+enter_times[end_st]+dst;
}
int main(){
    FILE* in=fopen("subway.in","r");
    FILE* out=fopen("subway.out","w");
    int c,n,m,d,q;// c测试点编号 n地铁线路数 m地铁站数 d地铁站线路数 q计划数
    fscanf(in,"%d %d %d %d %d\n",&c,&n,&m,&d,&q);
    for(int i=0;i<m;i++){
        fscanf(in," %d",&enter_times[i]);
    }
    for(int i=0;i<n;i++){
        fscanf(in," %d",&(metro_line[i].station_count))
        metro_line[i].stations_index=(int*)malloc(sizeof(int)*metro_line[i].station_count);
        metro_line[i].stations_exit_time=(int*)malloc(sizeof(int)*metro_line[i].station_count);
        for(int j=0;j<metro_line[i].station_count;j++){
            fscanf(in," %d %d",&(metro_line[i].stations_index[j]),&(metro_line[i].stations_exit_time[j]));
            use_count[metro_line[i].stations_index[j]]+=1;
            if(use_count[metro_line[i].stations_index[j]]>1){
                for(int k=0;k<i;k++){
                    if(!switch_time[k][i])switch_time[k][i]=1000000001;
                    for(int l=0;l<metor_line[k].station_count&&metor_line[k].station_index[l]!=metro_line[i].stations_index[j];l++);
                    if(l<metor_line[k].station_count){
                        int temp=metro_line[i].stations_exit_time[j]+metro_line[k].stations_exit_time[l];
                        switch_time[k][i]=temp>switch_time[k][i]?switch_time[k][i]:temp;
                        switch_time[i][k]=switch_time[k][i]
                        for(int o=0;o<k;o++){
                            if(switch_time[k][o]){
                                switch_time[i][o]=switch_time[k][o]+switch_time[k][i];
                                switch_time[o][i]=switch_time[i][o];
                            }
                        }
                    }
                }
            }
            else{
                first_own[metro_line[i].stations_index[j]]=i;
            }
        }
    }
    for(int i=0;i<q;i++){
        int start,end_st;
        fscanf(in," %d %d",&start,&end_st);
        fprintf(out," %d",min_disten_calc(start,end_st,n,m));
    }
    fclose(in);
    fclose(out);
    return 0;
}
