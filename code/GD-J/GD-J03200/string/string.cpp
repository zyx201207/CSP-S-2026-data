#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,cnt;
struct node{
	long long a;
	char c;
}x[N];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].c;
	}
	int L=1,R=n;
	while(L<R){
		if(x[L].c==x[R].c){
			if(x[L].a==x[R].a){
				L++;
				R--;
			}
			else{
				long long minn=(x[L].a,x[R].a);
				x[L].a-=minn;
				x[R].a-=minn;
				if(x[L].a==0){
					L++;
				}
				if(x[R].a==0){
					R--;
				}
			}
		}	
		else{
			if(x[L].a==x[R].a){
				L++;
				R--;
				cnt+=x[L].a;
			}
			else{
				long long minn=min(x[L].a,x[R].a);
					x[L].a-=minn;
					x[R].a-=minn;
					if(x[L].a==0){
						L++;
					}
					if(x[R].a==0){
						R--;
					}
					cnt+=minn;
			}
		}
	}
	cout<<cnt;
	return 0;
} 
