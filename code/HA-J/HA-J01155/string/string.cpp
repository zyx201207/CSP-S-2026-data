#include<iostream>
using namespace std;

const int N=2*1e5;
int n;
struct node{
	int a;
	char c;
};
node l[N+1];
long long ans=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i].a>>l[i].c;
	}
	
	int L=1,R=n;
	while(L<R){
		if(l[L].c==l[R].c){
			if(l[L].a<l[R].a){
				l[R].a-=l[L].a;
				L++;
			}
			else if(l[L].a>l[R].a){
				l[L].a-=l[R].a;
				R--;
			}
			else if(l[L].a==l[R].a){
				L++,R--;
			}
		}
		else{
			if(l[L].a<l[R].a){
				l[R].a-=l[L].a;
				ans+=l[L].a;
				L++;
			}
			else if(l[L].a>l[R].a){
				l[L].a-=l[R].a;
				ans+=l[R].a;
				R--;
			}
			else if(l[L].a==l[R].a){
				ans+=l[L].a;
				L++,R--;
			}
		}
	}
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
