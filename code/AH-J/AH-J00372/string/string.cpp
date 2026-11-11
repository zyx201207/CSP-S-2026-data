#include<bits/stdc++.h>
using namespace std;
struct tdd{
	long long a;
	char c;
}l[200010];
int main(){	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long sm=0;
	for(int i=1;i<=n;i++){
		cin>>l[i].a>>l[i].c;
		sm+=l[i].a;
	}
	long long sum=0,z=1,y=n;
	while(z<y){
		if(l[z].c==l[y].c){
			int ll=min(l[z].a,l[y].a);
     		l[z].a-=ll;
			l[y].a-=ll;
			if(l[z].a==0){
				z++;
			}
			if(l[y].a==0){
				y--;
			}
		}else{
			int ll=min(l[z].a,l[y].a);
			sum+=ll;
			l[z].a-=ll;
			l[y].a-=ll;
			if(l[z].a==0){
				z++;
			}
			if(l[y].a==0){
				y--;
			}
		}
	}
	cout<<sum;
	return 0;
}
