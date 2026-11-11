#include <bits/stdc++.h>
using namespace std;
int n,ans=0,ESC=0,lengthh;
long long m,temp;
long long anergy[500005]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>anergy[i];
	}
	lengthh=n;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(anergy[i]>anergy[j]){
				temp=anergy[i];
				anergy[i]=anergy[j];
				anergy[j]=temp;
				j=i+1;
			}
		}
	}
	for(long long i=1;i<=m;i++){
		anergy[1]=anergy[1]+1;
		for(int j=1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				if(anergy[j]>anergy[k]){
					temp=anergy[j];
					anergy[j]=anergy[k];
					anergy[k]=temp;
					k=j+1;
				}
			}
		}
	}
	
	//第一次合成 
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(anergy[i]==anergy[j]){
				anergy[i]=anergy[i]+anergy[j];
				for(int k=j;k<n;k++){
					anergy[k]=anergy[k+1];
				}
				ESC=1;
				n--;
				break;
			}
		}
		if(ESC==1)break;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(anergy[i]==anergy[j]){
				anergy[i]=anergy[i]+anergy[j];
				for(int k=j;k<n;k++)anergy[k]=anergy[k+1];
				n--;
				i=0;
				j=i+1;
			}
		}
	}
	
	ans=lengthh-n+1;
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
