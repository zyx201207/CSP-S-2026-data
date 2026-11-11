#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char a1;
};
int ans=0;
void change(string s1){
	int l=0,r=s1.size()-1;
	while(l<r){
		if(s1[l]==s1[r]){
			l++;
			r--;
		}else{
			s1[r]=s1[l];
			ans++;
			l++;
			r--;
		}
	}
	while(l<r){
		if(s1[l]==s1[r]){
			l++;
			r--;
		}else{
			s1[r]=s1[l];
			ans++;
			l++;
			r--;
		}
	}
}
int main(){
	int n;
	cin>>n;
	node g[200001]={};
	for(int i=0;i<n;i++){
		cin>>g[i].a>>g[i].a1;
	} 
	string s;
	int cnt=g[0].a,k=0;
	while(1){
		if(g[k+1].a==0&&g[k].a==0){
			break;
		}
		if(cnt!=0){
			s+=g[k].a1;
			cnt--;
		}else{
			k++;
			cnt=g[k].a;
		} 
	}
	change(s);
	cout<<ans;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	return 0;
}
