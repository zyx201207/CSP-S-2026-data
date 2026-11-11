#include <bits/stdc++.h>
using namespace std;
struct str{
	long long num;
	char s;
}a[200005];
char b[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long day=1,ans=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].s;
		for(int j=1;j<=a[i].num;j++){
				b[day]=a[i].s;
				day++;
		}
	}
	//for(int i=1;i<=day-1;i++)cout<<b[i]<<" ";
	//cout<<endl; 
	for(int i=1;i<=day-1;i++){
		if((day-1)%2==1){
			if(i>day/2)break;
		}
		else{
			if(i>(day-1)/2)break;
		}
		if(b[i]!=b[day-i])ans++;
	}
	cout<<ans<<endl;
	return 0;
}
