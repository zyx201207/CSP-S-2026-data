#include<bits/stdc++.h>
using namespace std;
struct node{
	long long id;
	char c;
}a[200005];
int n;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].id>>a[i].c;
	int l=1,r=n;
	while(l<=r){
		if(a[l].c==a[r].c){
			if(a[l].id<a[r].id){
				a[r].id-=a[l].id;
				l++;
			}
			else if(a[l].id==a[r].id){
				l++;
				r--;
			}
			else{
				a[l].id-=a[r].id;
				r--;
			}
		}
		else{
			if(a[l].id<a[r].id){
				sum+=a[r].id-a[l].id;
				a[r].id-=a[l].id;
				l++;
			}
			else if(a[l].id==a[r].id){
				sum+=a[r].id;
				l++;
				r--;
			}
			else{
				sum+=a[l].id-a[r].id;
				a[l].id-=a[r].id;
				r--;
			}	
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
