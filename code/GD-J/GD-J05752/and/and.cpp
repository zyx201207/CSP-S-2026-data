#include<bits/stdc++.h>
using namespace std;
int a[10005],cnt,ljx;
string c[10005];
string s,s1,ans;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i]; 
	} 
	sort(a+1,a+1+n,cmp);
	while(a[1]>0){
		s1=s1+char(a[1]%2);
		a[1]/2;
	}
	for(int i=s1.size()-1;i>=0;i--){
		s=s+s1[i];
	}//最大量身定做
	 
	for(int i=1;i<=m;i++){
		while(a[i]>0){
		s1=s1+char(a[1]%2);
		a[1]/2;
	}
	for(int j=s1.size()-1;j>=0;j--){
		c[i]=c[i]+s1[j];
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]==1){
			for(int j=1;j<=m-1;j++){
				string w=c[j];
				if(w[i]==1){
					cnt++;
				}
			}
			if(cnt>=n){
				ans[i]=1;
			}
		}
	}
	int jx=1;
	for(int i=ans.size()-1;i>=0;i--){
		ljx+=ans[i]*jx;
		jx*2;
		
	}
	cout<<ljx;
	} 

