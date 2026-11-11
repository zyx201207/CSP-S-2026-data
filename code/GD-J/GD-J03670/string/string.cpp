#include <bits/stdc++.h>
using namespace std;
const int mn=200005;
int n,num[mn]={};
char ch[mn]={};
int shengzuo=-1,sheng_num=0,sheng_char,scz=0,scr=0;
unsigned long long ans=0,np=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen('string.in','r',stdin);
	freopen('string.out','w',stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>num[i]>>ch[i];
	for(int i=1;i<=n/2;i++){
		if(num[i+scz]<num[n-i+1-scr]){
			if(ch[i+scz] != ch[n-i+1-scr])ans+=num[i+scz];
			sheng_num=num[n-i+1-scr]-num[i+scz];
			sheng_char=ch[n-i+1-scr];
			shengzuo=0;
		}else if(num[i+scz]>num[n-i+1-scr]){
			if(ch[i+scz] != ch[n-i+1-scr])ans+=num[n-i+1-scr];
			sheng_num=num[i+scz]-num[n-i+1-scr];
			sheng_char=ch[i+scz];
			shengzuo=1;
		}else{
			if(ch[i+scz] != ch[n-i+1-scr])ans+=num[n-i+1-scr];
			sheng_num=0;
			sheng_char=ch[i+scz];
		}
		if(sheng_num!=0){
			if(shengzuo){//×ó±ßÓÐÊ£µÄ 
				while(sheng_num!=0){
					scr++;
					if(sheng_num<=num[n-i+1-scr]){
						if(sheng_char!=ch[n-i+1-scr])ans+=sheng_num;
						num[n-i+1-scr]-=sheng_num;
						sheng_num=0;
					}else{
						if(sheng_char!=ch[n-i+1-scr])ans+=num[n-i+1-scr];
						sheng_num-=num[n-i+1-scr];
					}
				}
			}else{
				while(sheng_num!=0){
					scr++;
					if(sheng_num<=num[i+scz]){
						if(sheng_char!=ch[i+scz])ans+=sheng_num;
						num[i+scz]-=sheng_num;
						sheng_num=0;
					}else{
						if(sheng_char!=ch[i+scz])ans+=num[n-i+1-scr];
						sheng_num-=num[i+scz];
					}
				}
			}
		}
	}
	cout<<ans;
} 
