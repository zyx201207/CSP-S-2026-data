/*
HAPPY AFO :)

#include<bits/stdc++.h>
using namespace std;
#define int long long
int lx,rx;
int input1(int l,int r){
	int x;
	cin>>x;
	return x;
}
int input2(int l,int r){
	int x;
	x=rand()%(r-l+1)+l;
	return x;
}
int input3(int l,int r){
	int x;
	x=(l*r)%(r-l+1)+l;
	return x;
}
signed main(){
	srand(time(0));
	int l=1,r;
	cin>>rx;
	int sum1=0,sum2=0;
	for(int i=1;i<=100000;i++){
		r=rx;
		l=1;
		int ans=(rand()+rand())%r;
		if(ans==0)ans++;
		while(1){
			int cl;
//			cout<<l<<"~"<<r<<":\n";
			cl=input2(l,r);
//			cout<<cl<<" ";
//			_sleep(10);
			if(cl==ans){
	//			cout<<cl<<"\n";
				sum1++;
//				cout<<"END\n";
				break;
			}else{
				if(ans>cl){
					l=cl+1;
				}else if(ans<cl){
					r=cl-1;
				}
	//			cout<<l<<"~"<<r<<":\n";
				int k=input3(l,r);
//				_sleep(10);
//				cout<<k<<"  ";
				cl=k;
				if(ans>cl){
					l=cl+1;
				}else if(ans<cl){
					r=cl-1;
//					cout<<cl<<"-"<<r<<"-"<<ans<<'\n';
				}else{
					sum2++;
//					cout<<"WIN\n";
					break;
				}
			}
		}
	}
	cout<<sum1<<":"<<sum2<<"\n";
	
	return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	return 0;
}
