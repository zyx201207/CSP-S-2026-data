#include<iostream>
#define int long long
using namespace std;
int a[2000003];
char b[2000004];	
int lin;
int n;
int ppos=1,hpos;
int hyu=0;
int cnt=0;
int ans=0,sum=0;
bool flag;
void f(){
	if(a[hpos]>a[ppos]){
		flag=true;
		if(b[ppos]==b[hpos]){
			a[hpos]-=a[ppos];
		}else{
			a[hpos]-=a[ppos];
			ans+=a[ppos];
		}
		ppos++;
	}
	else if(a[hpos]==a[ppos]){
		flag=true;
		if(b[hpos]!=b[ppos]){
			ans+=a[ppos];
		}
		hpos--;
		ppos++;
	}	
} 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	hpos=n;
	string s;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		cnt+=a[i];
	}
	lin=cnt/2;
	for(;sum<lin;){
		flag=false;
		sum+=a[ppos];
		f();
		if(!flag) while(a[ppos]){
			if(a[ppos]<=a[hpos]){
				break;
			}else{
				if(b[ppos]==b[hpos]){
					a[ppos]-=a[hpos]; 
				}else{
					a[ppos]-=a[hpos];
					ans+=a[hpos];
				}
				hpos--;
			}
		}
		if(!flag) f();
	}
	cout<<ans;
	return 0;
}

