#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum;
struct xxx{
	int cnt;
	char c;
}a[200011];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].cnt>>a[i].c;
	for(int i=1,j=n;i<j;){
		if(a[i].c!=a[j].c){
			if(a[i].cnt<a[j].cnt){
				sum+=a[i].cnt;
				a[j].cnt-=a[i].cnt;
				i++;
			}
			else if(a[i].cnt>a[j].cnt){
				sum+=a[j].cnt;
				a[i].cnt-=a[j].cnt;
				j--;
			}
			else{
				sum+=a[i].cnt;
				i++,j--;
			}
		}
		else{
			if(a[i].cnt<a[j].cnt){
				a[j].cnt-=a[i].cnt;
				i++;
			}
			else if(a[i].cnt>a[j].cnt){
				a[i].cnt-=a[j].cnt;
				j--;
			}
			else i++,j--;
		}
	}
	cout<<sum;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
