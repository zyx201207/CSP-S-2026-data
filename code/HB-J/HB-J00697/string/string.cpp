#include<bits/stdc++.h>
using namespace std;
struct node{
	long long num;
	char le;
	long long k;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	node t[200020];
	for(int i=1;i<=n;i++){
		cin >> t[i].num >> t[i].le;
		t[i].k=t[i].le-'a';
	}
	long long l=1,r=n;
	long long p1=t[1].num,p2=t[n].num;
	long long k1=t[1].k,k2=t[n].k;
	long long ans=0;
	while(l<=r){
		//cout << k1 <<" " << k2 << endl;
		if(k1==k2){
			if(p1>=p2){
				p1=p1-p2;
				//cout <<"1" << " p2:" << p2 << " " << " p1:" << p1<< k2 << endl;
				p2=0;
			}else{
				p2=p2-p1;
				//cout <<"2" << " p1:" << p1<< " p2:" << p2 << " " << k1 << endl;
				p1=0;
			}
		}else{
			if(p1>=p2){
				p1=p1-p2;
				//cout <<"3" << " p2:" << p2 << " " << " p1:" << p1<< k2 << endl;
				ans+=p2;
				p2=0;
			}else{
				p2=p2-p1;
				//cout <<"4" << " p1:" << p1<< " p2:" << p2 << " " << k1 << endl;
				ans+=p1;
				p1=0;
			}
		}
		if(p1==0){
			l++;
			p1=t[l].num;
			k1=t[l].k;
		}
		if(p2==0){
			r--;
			p2=t[r].num;
			k2=t[r].k;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
