#include<bits/stdc++.h>;
using namespace std;
int n,m;
int arr[500005];
int p[500005];
int s[500005];
int index=0;
bool check(int x,int temp){
	for(int i=1;i<=temp;i++){
		if(p[i]==x){
			index=i;
			return true;
		}
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	for(int i=1;i<=n;i++){
		int temp=1;
		int a=i;
		while(a<=n){
			if(check(arr[a],temp)){
				for(int j=index+1;j<=temp;i++){
					p[j]=0;
				}
				temp=index+1;
			}
			p[temp]=arr[a];
			temp++;
			a++;
		}
		for(int j=1;j<=n-i;j++){
			s[p[j]]++;
			p[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i];
	}
	return 0;
}
