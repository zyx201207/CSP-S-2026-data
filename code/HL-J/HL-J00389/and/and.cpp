#include<bits/stdc++.h>
using namespace std;
int n,m,num,max1=INT_MIN;
int a[200005];
string s1,s[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
		num=a[i];
		while(num!=0){
			s1+=num%2;
			num/=2;
		}
		for(int k=s1.size()-1,j=0;k>=0,j<=s1.size()-1;k--,j++){
			s[i][j]=s1[k];			
		}
	}
	if(m==1){
		cout<<max1;
	}
	string p=s[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
