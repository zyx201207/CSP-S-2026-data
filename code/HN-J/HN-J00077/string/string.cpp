#include<bits/stdc++.h>
#define  long long int
using namespace std;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,c[100010],m=0,d[27]={0};
	char b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		c[int(b)-96]+=a;
	}
	int j=1;
	for(int i=1;i<=26;i++){
		if(c[i]!=0){
			m++;
			d[j]=c[i];
			j++;
		}
	}
	int s1=0,s2=0;
	if(m%2==1){
		for(int i=1;i<=m/2;i++){
			s1+=d[i];
		}
		for(int i=m/2+2;i<=m;i++){
			s2+=d[i];
		}
		cout<<max(s1,s2);
	}else{
		for(int i=1;i<=m/2;i++){
			s1+=d[i];
		}
		for(int i=m/2+1;i<=m;i++){
			s2+=d[i];
		}
		cout<<min(s1,s2);
	}
	return 0;
} 
