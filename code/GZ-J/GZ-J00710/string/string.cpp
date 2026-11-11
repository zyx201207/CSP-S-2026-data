//GZ-J00710 贵阳市第三实验中学 王埼煌
#include<bits/stdc++.h>
using namespace std;
int xg(char s[],int ans){
	int r=ans-1;
	int t=0;
	for(int l=0;l<ans/2;l++)
	{
		if(s[l]!=s[r]) t+=1;
		r--;
	}
	return t;
}
char s[20005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	int o=0;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		ans+=x;
		char w;
		cin>>w;
		for(int j=1;j<=x;j++){
			s[o]=w;
			o++;
		}
	}
	int r=ans-1;int l;
	for(l=0;l<ans/2;l++)
	{
		if(s[l]!=s[r]) break;
		r--;
	}
	if(l==ans) {
		cout<<0;
		return 0;
	}
	cout<<xg(s,ans);
	fclose(stdin);
	fclose(stdout);
	return 0;

}
