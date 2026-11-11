#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005][3],ans,jian;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		char temp;
		cin>>a[i][0]>>temp;
		a[i][1]=temp-'a';
	}
	for(int i=0,j=n-1-i;i<j;){
		jian=min(a[i][0],a[j][0]);
	    a[i][0]-=jian;
	    a[j][0]-=jian;
		if(a[i][1]!=a[j][1])ans+=jian;
		if(!a[i][0])i++;
		if(!a[j][0])j--;
	}
	cout<<ans;
	return 0;
}
