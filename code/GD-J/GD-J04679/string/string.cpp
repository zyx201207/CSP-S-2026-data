#include<bits/stdc++.h>
using namespace std;

int n;
struct str{
	int num;
	char c;
}a[200086];

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	
	long long ans=0;
	int l=1,r=n;
	
	while(l<r){
		int m=min(a[l].num,a[r].num);
		if(a[l].c!=a[r].c){
			ans+=m;
		}
		a[l].num-=m;
		a[r].num-=m;
		if(a[l].num==0){
			l++;
		}
		if(a[r].num==0){
			r--;
		}
	}
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
