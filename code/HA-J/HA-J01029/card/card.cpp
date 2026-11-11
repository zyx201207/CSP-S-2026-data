#include<bits/stdc++.h>
using namespace std;
int a[500005],t[500005];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(t[a[i]]==0)t[a[i]]=i;
	}
	if(m==1){
		cout<<1;
		return 0;
	}
//	for(int i=1;i<=n;i++){
//		int c=0;
//		for(int j=1;j<=n;j++){
//			s[j]=0;
//		}
//		for(int j=i;j<=n;j++){
//			s+=a[j];
//			if(s.find(a[j])!=-1){
//				int pos=s.find(a[j]);
//				s.erase(pos,s.size()-pos);
//			}
//		}
//		for(int i=0;i<s.size();i++){
//			t[s[i]]++;
//		}
//	}
	for(int i=1;i<=m;i++){
		cout<<n-t[i]+1<<' ';
	}
	return 0;
}
