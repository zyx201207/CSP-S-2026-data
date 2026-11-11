#include <bits/stdc++.h>
using namespace std;
int n,m;
int s[500100],ss[500100];
int ll[500100],ls[500100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		int f=0;
		for(int j=i;j<n;j++){
			//cout<<f;
			if(ls[s[j]]==0){
				ll[f]=s[j];
				ls[s[j]]=f+1;
				f++;
				//cout<<"gg";
			}else{
				int h=0;
				for(int x=ls[s[j]]+1;x<f;x++){
					ls[s[x]]=0;
					//ll[x]=0;
					h++;
				}
				f=ls[s[j]];
			}
		}
		for(int j=0;j<n;j++) ls[s[j]]=0;
		for(int j=0;j<f;j++) ss[ll[j]]++;
		//for(int j=0;j<f;j++) cout<<ll[j];
		//cout<<endl;
	}
	for(int j=0;j<500100;j++){
		if(ss[j]!=0){
			cout<<ss[j]<<" ";
		}
	}
	return 0;
}
