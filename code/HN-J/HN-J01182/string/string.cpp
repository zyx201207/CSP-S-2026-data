#include<bits/stdc++.h>
using namespace std;
#define int long long

struct number{
	int a;
	string b;
};
number q[200000];
number q1[200000];
number q2[200000];

signed main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	
	int cishu=0;
	int zhong=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i].a>>q[i].b;
	}
	for(int i=1;i<=n;i++){
		q1[i].a=q[i].a;
		q1[i].b=q[i].b;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(q[i].b==q[j].b){
				q[i].a+=q[j].a;
				q[j].a=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(q[i].a%2){
			zhong=i;
		}
	}

	int maxi=1;
	if(zhong==0){
		for(int j=1;j<=n;j++){
			int maxa=q[j].a;
			for(int i=1;i<=n;i++){
				if(maxa<=q[i].a){
					maxa=q[i].a;
					maxi=i;
				}
			}
			q2[j].a=maxa;
			//cout<<maxi<<endl;
			q[maxi].a=0;
		}
		//cout<<n/2;
		//for(int i=1;i<=n/2;i++){
		//	q2[i].a/=2;
		//	q2[n+1-i].a+=q2[i].a;
		//}
		int maxb=q2[1].a;
		for(int i=2;i<=n;i++){
			if(maxb<=q2[i].a){
				maxb=q2[i].a;
			}
		}
		cout<<maxb/2;
	}else{
		q[zhong].a=0;
		for(int i=1;i<=n;i++){
			cishu+=q[i].a/2;
		}
		cout<<cishu;
	}
	//for(int i=1;i<=n;i++){
	//	cout<<q[i].a<<q[i].b<<q2[i].a<<endl;
	//}
	return 0;
} 
