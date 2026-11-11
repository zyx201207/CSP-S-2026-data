#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,t1=1,t2;
	cin>>a;
	long long u[a+1],sum=0;
	char s[a+1];
	for(int i=1;i<=a;i++){
		cin>>u[i]>>s[i];
	}
	t2=a;
	while(t1<t2){
		if(s[t1]!=s[t2]){
			if(u[t1]>u[t2]){
				sum+=u[t1];
				u[t2]-=u[t1];
				u[t1]=0;
				t1++;
			}else{
				sum+=u[t2];
				u[t1]-=u[t2];
				u[t2]=0;
				t2--;
			}
		}else{
			if(u[t1]>u[t2]){
				u[t2]-=u[t1];
				u[t1]=0;
				t1++;
			}else{
				u[t1]-=u[t2];
				u[t2]=0;
				t2--;
			}
		}
		if(u[t1]==0)t1++;
		if(u[t2]==0)t2--;
	}
	
	cout<<sum;
	return 0;
}

