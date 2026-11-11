#include<bits/stdc++.h>
using namespace std;
int a[500005],t[500005],s[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=1,num=0;
	for(int dj=1;dj<=n;dj++){
		num=0,cnt=1;
		for(int i=num+dj;i<=n;i++){
			for(int j=1;j<=cnt;j++){
				if(a[i]==t[j]){
					cnt=1;
					t[cnt]=a[i];
				}else{
					t[cnt]=a[i];
				}
			}
			cnt++;
			num++;
			cout<<cnt<<" "<<num<<endl;
		}
		for(int i=1;i<=cnt;i++)cout<<t[i];
		for(int i=1;i<=cnt;i++){
			s[t[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
