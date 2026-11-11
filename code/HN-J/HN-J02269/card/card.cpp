#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0,b=0,re=0;
int a[300005];
int a1[300005];
string s;
struct c{
	int num;
}card[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("crad.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		a[i]=0;
	}
	for(int i=0;i<n;i++){
		cin>>card[i].num;
	}
	for(int l=0;l<n;l++){
		for(int i=l;i<n;i++){
			sum=card[i].num;
			if(a[sum]<2){
				a[sum]++;
			}
			if(a[sum]==2){
				for(int j=re;j<re+m;j++){
					if(s[j]==sum){
						b=j;
					}
				}
				for(int j=re;j<re+m;j++){
					a[s[j]]=1;
					s[j]=0;
				}
			}
			char f;
			f=sum+'0';
			s=s+f;
		}
		re=s.length();
		cout<<re;
		for(int i=1;i<=m;i++){
			a[i]=0;
		}
	}
	cout<<s<<endl;
	for(int i=0;i<s.length();i++){
		a1[s[i]-'0']++;
	}
	for(int i=1;i<=m;i++){
		cout<<a1[i]<<" ";
	}
	return 0;
}

