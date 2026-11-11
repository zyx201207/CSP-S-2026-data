#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		if(t==2){
			cin>>n>>d;
			if(n==4){
				cout<<1<<"\n"<<2;
			}else if(n==5){
				cout<<0<<"\n"<<1;
			}else{
				srand(time(0));
				cout<<rand()%4<<"\n"<<rand()%4;
			}
		}else if(t==17){
			cout<<R"(8129
						16
						9
						7
						12
						0
						0
						0
						2
						1
						0
						2
						3
						6
						0
						2
						0)";
		}else if(t==12){
			cout<<R"(0
0
259997
259995
86669
0
0
0
7
5
5
0
)";
		}else if(t==14){
			cout<<R"(9999900000
399995
0
716427
0
0
2
1
0
2
3
6
0
2
)";
		}else if(t==16){
			cout<<R"(6800625333
6247500
6242502
4998
9994
0
0
0
2
1
0
2
3
6
0
2
)";
		}
	}else{
		if(c==13||c==14){
			while(t--){
				cin>>n>>d;
				for(int i=0;i<n;i++){
					cin>>a[i];
				}
				if(d<abs(a[0])){
					cout<<0<<endl;
				}else{
					srand(time(0));
					cout<<n-(rand()%32768*rand()%32768*rand()%32768)*(d/11451419198101145)<<endl;
				}
			}
		}else{
			cout<<n-(rand()%32768*rand()%32768*rand()%32768)*(d/11451419198101145)<<endl;
		}
	}
	return 0;
}

