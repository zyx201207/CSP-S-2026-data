#include<bits/stdc++.h>
using namespace std;
const int N=500010;
int n,m;
int a[N];
int t[N];
int ans[N];
void S_only_one(){
	for(int i=1;i<=m;i++){
		cout<<i<<" ";
	}
	cout<<endl;
	return;
}
void S_small(){
	for(int i=1;i<=n;i++){
		int s[N];
		for(int i=1;i<=m;i++)s[i]=0;
		int len=0;
		for(int j=i;j<=n;j++){
			if(s[a[j]]==0){
				s[a[j]]=len+1;
				len++;
			}else{
				for(int k=1;k<=m;k++){
					if(s[k]>s[a[j]]){
						s[k]=0;
						len--;
					}
				}
				s[a[j]]=len+1;
				len++;
			}
		}
		for(int j=1;j<=m;j++){
			//cout<<s[j]<<" ";
			if(s[j]!=0){
				ans[j]++;
			}
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return;
}
void S(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
	}
	bool ck=1;
	for(int i=1;i<=m;i++){
		if(t[i]>1){
			ck=0;
			break;
		}
	}
	if(ck){
		S_only_one();
		return;
	}
	if(n<=500||1){
		S_small();
		return;
	}
	/*
10 3
3 1 2 1 3 2 3 1 2 1
	*/
	return;
}
int main(){
	//CARDS!!!!!
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int CCF=1;
	//cin>>_;
	while(CCF--) S();
	return 0;
}

