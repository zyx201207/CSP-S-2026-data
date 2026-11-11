#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
void change(string s,int &ans){
	int len=s.size()-1,l=0;
	string t=s;
	while(l<=len/2){
		if(t[l]!=t[len-l]){
			t[len-l+1]=t[l];
			ans++;
		}
		l++;
	}
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	string s="";
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int ans=0;
	change(s,ans);
	printf("%d",ans);
	return 0;
}
