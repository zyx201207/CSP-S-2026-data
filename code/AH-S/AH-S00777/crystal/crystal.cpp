#include<bits/stdc++.h>
using namespace std;
long long m1[2500006];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>m1[i];
	}
	sort(m1+1,m1+n);
	int x=1,x1=1,L1=1,R1=1,LL=1;
	for(int i=1;i<=n;i++){
		if(m1[i]+1==m1[i+1]||m1[i]==m1[i+1]){
			x++;
		}else{
			if(x>x1){
				x1=x;
				L1=LL;
				R1=i;
				x=1;
			}
			LL=i;
		}
	}
	int y1=1,y=1;
	int f=0;
	int R2=R1;
	R1--;
	while(1){
		if(y1>m){
			f=3;
			break;
		}else{
			m-=y1; 
			y1=y1+m1[R1+1]-m1[R1];
			--R1;
			++y;
		}
	}
	int y3=y;
	while(L1>1){
		--L1;
		if(f==1){
			while(1){
				if((m1[R2]-m1[L1])<=m&&m>0&&L1>0){
					++y;
					m=m-(m1[R2]-m1[L1]);
					--L1;
				}else{
					break;
				}
			}
		}
		break;
	}
	int R3=R2;
	while(R2<n&&f!=3){
		++R2;
		while(1){
			if((m1[R2]-m1[R3])*(y3+1)<=m){
				m=m-(m1[R2]-m1[R3])*(y3+1);
				++R2;
				++y3;
			}else{
				if(y3>y){
					y=y3;
					break;
				}
			}
		}
	}
	cout<<y<<endl;
	return 0;
}
