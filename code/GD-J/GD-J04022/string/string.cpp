#include <bits/stdc++.h>
using namespace std;
int n;
struct edge{
	int a;
	char c;
}surf[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>surf[i].a;
		cin>>surf[i].c;
	}
	int front=1;
	int last=n;
	int f1=surf[1].a,f2=surf[n].a;
	while(front<last){
		if(surf[front].c==surf[last].c){
			if(f1<f2){
				f2-=f1;
				front++;
				f1=surf[front].a;
			}
			else if(f1==f2){
				front++;
				f1=surf[front].a;
				last--;
				f2=surf[last].a;
			}
			else{
				f1-=f2;
				last--;
				f2=surf[last].a;
			}
		}
		else{
			if(f1<f2){
				ans+=f1;
				f2-=f1;
				front++;
				f1=surf[front].a;
			}
			else if(f1==f2){
				ans+=f1;
				front++;
				f1=surf[front].a;
				last--;
				f2=surf[last].a;
			}
			else{
				ans+=f2;
				f1-=f2;
				last--;
				f2=surf[last].a;
			}
		}
	}
	cout<<ans;
	return 0;
}
