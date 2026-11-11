// SPDX-License-Identifier: MPL-2.0
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
long crys[500000];
char crys_able[500000];
template<typename K,typename V> struct mapping{ // C++难死我了，除了声明确实比C难点（）
public:
    size_t max_size,curr_size;
    K* keys;
    V* values;
    char* flags;
    mapping(){
        this->keys=(K*)malloc(sizeof(K)*4);
        this->values=(V*)malloc(sizeof(V)*4);
        this->flags=(char*)calloc(4,1);
        max_size=4;
        curr_size=0;
    }
    ~mapping(){
        free(keys);
        free(values);
        free(flags);
    }
    void set(K key,V value){
        if(max_size==curr_size){
            max_size*=2;
            auto new_keys=(K*)malloc(sizeof(K)*max_size); // 扩容非常简单粗暴（）
            auto new_values=(V*)malloc(sizeof(V)*max_size);
            auto new_flags=(char*)calloc(max_size,1);
            mapping<K,V> a;
            a.keys=new_keys;
            a.values=new_values;
            a.flags=new_flags;
            a.max_size=max_size;
            a.curr_size=0;
            for(size_t i=0;i<curr_size;i++){
                a.set(keys[i],values[i]);
            }
            a.keys=nullptr;
            a.values=nullptr;
            a.flags=nullptr;
        }
        K temp=key&(max_size-1),temp2=key;
        while((flags[temp]&&flags[temp]!=2)||keys[temp]==key){
            temp2>>=5;
            temp=(temp*5+temp2)&(max_size-1);
        }
        if(flags[temp]&&flags[temp]!=2)curr_size+=1;
        flags[temp]=1;
        values[temp]=value;
    }
    V get(K key,V dft){
        if(!curr_size)return dft;
        K temp=key&(max_size-1),temp2=key;
        while(flags[temp]||keys[temp]==key){
            temp2>>=5;
            temp=(temp*5+temp2)&(max_size-1);
        }
        if(keys[temp]==key){
            return values[temp];
        }
        return dft;
    }
};
int main(){
    FILE* in=fopen("crystal.in","r");
    FILE* out=fopen("crystal.out","w");
    int n;
    long m;
    fscanf(in,"%d %ld",&n,&m);
    for(int i=0;i<n;i++)fscanf(in," %ld",crys+i);
    mapping<long,int> mp;
    for(int i=0;i<n;i++){
        mp.set(crys[i],mp.get(crys[i],0)+1);
    }
    int max_val=0,count_last=0;
    long max_key;
    for(int i=0;i<n;i++){
        if(mp.get(crys[i],0)>max_val)max_val=mp.get(crys[i],0L),max_key=crys[i];
    }
    count_last=max_val;
    while(m){
        long max_c=-1000000000001L;
        for(int j=0;j<n;j++){
            max_c=max_c>crys[j]?max_c:crys[j]>max_key?max_c:crys[j];
        }
        int count_=0;
        for(int j=0;j<n;j++){
            crys_able[j]==(max_c==crys[j]);
            count_++;
        }
        if(m<count_*(max_key-max_c)){
            m=m/(max_key-max_c);
            count_last+=m;
            break;
        }
        count_last+=count_;
        m-=count_*(max_key-max_c);
    }
    fprintf(out,"%d",count_last);
    fclose(in);
    fclose(out);
    return 0;
}
