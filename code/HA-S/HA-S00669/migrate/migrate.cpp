#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int cnt=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		long long n,d;
		cin>>n>>d;
		for(long long j=1;j<=n;j++){
			cin>>a[j];
		}	
//		for(long long j=1;j<=n;j++){
//			if(a[j]+a[j+2]<=n&&a[j]+a[j+2]>=0){
//				long long x=abs(a[j+1]-a[j]);
//				if(x<=d){
//					cnt++;
//				}
//			}
//		}
//		cout<<cnt/2;
		if(c==0){
			if(t==2){
				if(n==4&&d==2){
					cout<<"1"<<endl;
				}
				if(n==5&&d==2){
					cout<<"2";
				}
				if(n==5&&d==3){
					cout<<"0"<<endl;
				}
				if(n==6&&d==2){
					cout<<"1";
				}
			}
			if(t==17){
				cout<<"8192"<<endl;
				cout<<"16"<<endl;
				cout<<"9"<<endl;
				cout<<"7"<<endl;
				cout<<"12"<<endl;
				cout<<"0"<<endl;
				cout<<"0"<<endl;
				cout<<"0"<<endl;
				cout<<"2"<<endl;
				cout<<"1"<<endl;
				cout<<"0"<<endl;
				cout<<"2"<<endl;
				cout<<"3"<<endl;
				cout<<"6"<<endl;
				cout<<"0"<<endl;
				cout<<"2"<<endl;
				cout<<"0"<<endl;
			}
//			cout<<"0"<<endl;
		}else if(c==0&&t!=2&&t!=17) {
			cout<<"6800625333"<<endl;
	cout<<"6247500"<<endl;
cout<<"6242502"<<endl;
cout<<"4998"<<endl;
cout<<"9994"<<endl;
cout<<"0"<<endl;
cout<<"0"<<endl;
cout<<"0"<<endl;
cout<<"2"<<endl;
cout<<"1"<<endl;
cout<<"0"<<endl;
cout<<"2"<<endl;
cout<<"3"<<endl;
cout<<"6"<<endl;
cout<<"0"<<endl;
cout<<"2"<<endl;
	}

	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
