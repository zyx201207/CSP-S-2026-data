#include<bits/stdc++.h>
using namespace std;
struct N{
	long long n;
	char c;
}a[200010];
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int m=0;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i].n>>a[i].c;
	}
	int l=1,r=m;
	//for(int i=1;i<=m;i++) cout<<a[i].n<<" "<<a[i].c<<endl;
	for(int i=2;i<=m;i++){
		if(a[i].c==a[i-1].c){
			a[i].n+=a[i-1].n;
			a[i-1].n=-1;
		}
	}
	while(l<=r){
		if(a[l].n==-1){
			l++;
		}else if(a[r].n==-1){
			r--;
		}
		else{
			if(a[l].c!=a[r].c){
				if(a[l].n<a[r].n){
					//cout<<1<<endl;
					a[r].n-=a[l].n;
					cnt+=a[l].n;
					l++;
				}else if(a[l].n>a[r].n){
					//cout<<2<<endl;
					a[l].n-=a[r].n;
					cnt+=a[r].n;
					r--;
				}else{
					//cout<<3<<endl;
					cnt+=a[l].n;
					l++,r--;
				}
			}else{
				if(a[l].n==a[r].n){
					l++,r--;
				}
				else if(a[l].n<a[r].n){
					a[r].n-=a[l].n;
					l++;
				}
				else if(a[l].n>a[r].n){
					a[l].n-=a[r].n;
					r--;
				}
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
