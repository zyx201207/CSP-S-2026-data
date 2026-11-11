#include<bits\stdc++.h>
using namespace std;
struct jihe{
int a;
	char c;
};
int main()
{ 
freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	 ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin>>n;
	
	jihe gunmu[200005];
	for( long long i=1;i<=n;i++){
		cin>>gunmu[i].a>>gunmu[i].c;
	}
	long long tou=1,wei=n;
	long long ans=0;
	while(tou<wei){
		if(gunmu[tou].c==gunmu[wei].c){
			if(gunmu[tou].a<gunmu[wei].a){
				gunmu[wei].a-=gunmu[tou].a;
				gunmu[tou].a=0;
				tou++;
			}else if(gunmu[tou].a==gunmu[wei].a){
				gunmu[tou].a=0;
				gunmu[wei].a=0;
				tou++;
				wei--;
			}else if(gunmu[tou].a>gunmu[wei].a){
				gunmu[tou].a-=gunmu[wei].a;
				gunmu[wei].a=0;
				wei--;
			}
		}else if(gunmu[tou].c!=gunmu[wei].c){
			if(gunmu[tou].a<gunmu[wei].a){
				ans+=gunmu[tou].a;
				gunmu[wei].a-=gunmu[tou].a;
				gunmu[tou].a=0;
				tou++;
			}else if(gunmu[tou].a==gunmu[wei].a){
				ans+=gunmu[tou].a;
				gunmu[tou].a=0;
				gunmu[wei].a=0;
				tou++;
				wei--;
			}else if(gunmu[tou].a>gunmu[wei].a){
				ans+=gunmu[wei].a;
				gunmu[tou].a-=gunmu[wei].a;
				gunmu[wei].a=0;
				wei--;
			}
		}
	}
	cout<<ans;
	return 0;
}
