#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string a[N];
int n,m;
void nor(){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[i].size()<a[j].size()){
				swap(a[i],a[j]);
			}else if(a[i].size()==a[j].size()){
				for(int k=a[i].size()-1;k>=0;k--){
					if(a[i][k]=='0' and a[j][k]=='1'){
						swap(a[i],a[j]);
						break;
					}
				}
			}
		}
	}
}
int km(int n){
	if(n==0){
		return 1;
	}
	if(n%2==0){
		int m=km(n/2);
		return m*m;
	}
	return 2*km(n-1);
}
int zh(string s){
	int sum=0,j=0;
	for(int i=s.size()-1;i>=0;i--,j++){
		sum+=(s[i]-'0')*km(j);
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int ma=0;
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		int sum=0;
		string s;
		while(num){
			char b=(num%2)+'0';
			s+=b;
			num/=2;
			sum++;
		}
		ma=max(ma,sum);
		a[i]=s;
	}
	nor();
	bool f[N]{};
	for(int i=ma;i>=1;i--){
		int sum=0,k=1;
		int b[N]{};
		for(int j=1;j<=n;j++){
			if(a[j][i]=='0'){
				break;
			}
			if(f[j] or i==ma){
				sum++;
				b[k]=j;
				k++;
			}
		}
		if(sum<m){
			continue;
		}
		if(sum==m){
			int sum=zh(a[b[1]]);
			for(int j=2;j<=m;j++){
				sum&=zh(a[b[j]]);
			}
			cout<<sum;
			return 0;
		}
		for(int j=1;j<=m;j++){
			f[b[j]]=1;	
		}
	}
	int ans,l;
	for(int i=1;i<=n;i++){
		if(f[i]){
			ans=zh(a[i]);
			l=i;
			break;
		}
	}
	int t=1;
	for(int i=l+1;i<=n;i++){
		if(t>=m){
			break;
		}
		if(f[i]){
			ans&=zh(a[i]);
			t++;
		}
	}
	cout<<ans;
	

	return 0;
}
