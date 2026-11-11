#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	unsigned long long ct=0,cnt=0;
	char flag=0;
	cin>>n;
	int a[n+9];
	char c[n+9];
	string s;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1;i<n;i++){
		if(c[i]==c[i+1]) flag=1;
		else{
			flag=0;
			break;	
		}
	}
	if(flag==1) cout<<0;
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				s+=char(c[i]);
			}
			ct+=a[i];
		}
		int ans1=0,ans2=ct-1;
		for(int i=0;i<(ct+1)/2;i++){
			if(s[ans1+i]!=s[ans2-i]){
				cnt++;
			}
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
