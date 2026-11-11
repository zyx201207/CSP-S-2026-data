#include<bits/stdc++.h>
using namespace std;
int n,cnt,cntt,x[200005];
char a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	string s;
	int sum=0;
	for(int i=1;i<=n;i++){
		int t=i;
		cin>>x[i]>>a;
		sum+=x[i];
		for(int i=1;i<=x[t];i++){
			s[cnt]=a;
			cnt++;
		}
	}
	int l=0,r=sum-1;
	while(r>=l){
		if(s[l]!=s[r]){
			cntt++;
			l++;
			r--;
		}else{
			l++;
			r--;
		}
	}
	cout<<cntt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
