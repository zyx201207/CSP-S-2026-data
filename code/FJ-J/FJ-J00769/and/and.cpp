#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],sum,b[31],c[200001];
string s[200001],s1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=1;
		while(k<=30){
			s[i]=char((a[i]%2)+'0')+s[i];
			if(a[i]%2==1){
				b[30-k]++;
			}
			a[i]/=2;
			k++;
		}
	}
	for(int i=0;i<=29;i++){
		if(b[i]>=m){
			for(int j=1;j<=n;j++){
				if(s[j][i]=='0'&&c[j]==0){
					for(int k=i;k<=29;k++){
						b[k]-=(s[j][k]-'0');
					}
					c[j]=1;
				}
			}
			s1='1'+s1;
		}
		else{
			s1='0'+s1;
		}
	}
	int h=1;
	for(int i=0;i<s1.size();i++){
		int d=(s1[i]-'0');
		sum+=(h*d);
		h*=2;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
