#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int> str;
int find(int x,int n){
	for(int i=0;i<n;i++){
		if(str[i]==x){
			return 1;
		}
		
	}
	return 0;
}
void po(int n){
	for(int i=0;i<n;i++){
		str.pop_back();
		
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[10005]={0};
	int ans[3]={0};
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(find(a[j],n)==0){
				str.push_back(a[j]);
				ans[a[j]-1]++;
			}else{
				po(n);
			}
		}
	}
	cout<<ans[0]<<ans[1]<<ans[2];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
