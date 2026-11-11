#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	long long m;
	char c;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].c;	
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].m>a[r].m){
				a[l].m-=a[r].m;
				r--;
			}else if(a[l].m<a[r].m){
				a[r].m-=a[l].m;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(a[l].m>a[r].m){
				a[l].m-=a[r].m;
				ans+=a[r].m;
				r--;
			}else if(a[l].m<a[r].m){
				a[r].m-=a[l].m;
				ans+=a[l].m;
				l++;
			}else{
				ans+=a[l].m;
				l++;
				r--;
			}	
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
