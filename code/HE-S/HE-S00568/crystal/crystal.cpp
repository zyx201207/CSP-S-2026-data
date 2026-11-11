#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int aa[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,res;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
	}
	for(int a=0;a<=9;a++){
		for(int b=0;b<=9;b++){
		    for(int c=0;c<=9;c++){
				for(int d=0;d<=9;d++){
					for(int e=0;e<=9;e++){
						if(a>=aa[1]&&b>=aa[2]&&c>=aa[3]&&d>=aa[4]&&e>=aa[5]){
							if(((a-aa[1])+(b-aa[2])+(c-aa[3])+(d-aa[4])+(e-aa[5]))==m){
								aa[1]=a;
								aa[2]=b;
						    	aa[3]=c;
								aa[4]=d;
								aa[5]=e;
							}
						}				
					}
				}
			}
	    }	
	}
	int cnt=0,cnt1=0,cnt2=0,cnt3=0,cnt4=0;
	for(int i=1;i<=5;i++){
		if(aa[i]==aa[1]) cnt++;
		if(aa[i]==aa[2]) cnt1++;
		if(aa[i]==aa[3]) cnt2++;
		if(aa[i]==aa[4]) cnt3++;
		if(aa[i]==aa[5]) cnt4++;
	}
	int t1,t2,t3,t4;
	t1=max(cnt,cnt1);
	t2=max(cnt2,cnt3);
	t3=max(t1,t2);
	t4=max(t3,cnt4);
	cout<<t4;
	return 0;
} 
