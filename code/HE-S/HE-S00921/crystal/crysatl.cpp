#include<bits/stdc++.h>
using namespace std;
long long n,m,ant=0;
long long a[50010];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5){
		for(int i=1;i<=n;i++){
			if(a[n-(n-1)]<0&&a[n-(n-2)]<0){
				cout<<-(a[n-(n-1)]+a[n-(n-2)]);
			}else cout<<a[n-(n-1)]+a[n-(n-2)];
			 break;
		}
	}if(n==6){
		for(int i=1;i<=n;i++){
			if(a[n-(n-1)]<0&&a[n-(n-2)]<0&&a[n-(n-3)]<0){
				cout<<-(a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]);
			}else cout<<a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)];
			 break;
		}
	}if(n==7){
		for(int i=1;i<=n;i++){
			if(a[n-(n-1)]<0&&a[n-(n-2)]<0&&a[n-(n-3)]<0&&a[n-(n-4)]<0){
				cout<<-(a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]);
			}else cout<<a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)];
			 break;
		}
	}if(n==8){
		for(int i=1;i<=n;i++){
			if(a[n-(n-1)]<0&&a[n-(n-2)]<0&&a[n-(n-3)]<0&&a[n-(n-4)]<0&&a[n-(n-5)]<0){
				cout<<-(a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]);
			}else cout<<a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)];
			 break;
		}
	}if(n==9){
		for(int i=1;i<=n;i++){
			if(a[n-(n-1)]<0&&a[n-(n-2)]<0&&a[n-(n-3)]<0&&a[n-(n-4)]<0&&a[n-(n-5)]<0&&a[n-(n-6)]<0){
				cout<<-(a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)]);
			}else cout<<a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)];
			 break;
		}
	}if(n==10){
		for(int i=1;i<=n;i++){
			if(a[n-(n-1)]<0&&a[n-(n-2)]<0&&a[n-(n-3)]<0&&a[n-(n-4)]<0&&a[n-(n-5)]<0&&a[n-(n-6)]<0&&a[n-(n-7)]<0){
				cout<<-(a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)]+a[n-(n-7)]);
			}else cout<<a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)]+a[n-(n-7)];
			 break;
		}
	}if(n==11){
		for(int i=1;i<=n;i++){
			if(a[n-(n-1)]<0&&a[n-(n-2)]<0&&a[n-(n-3)]<0&&a[n-(n-4)]<0&&a[n-(n-5)]<0&&a[n-(n-6)]<0&&a[n-(n-7)]<0&&a[n-(n-8)]<0){
				cout<<-(a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)]+a[n-(n-7)]+a[n-(n-8)]);
			}else cout<<a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)]+a[n-(n-7)]+a[n-(n-8)];
			 break;
		}
	}if(n==12){
		for(int i=1;i<=n;i++){
			if(a[n-(n-1)]<0&&a[n-(n-2)]<0&&a[n-(n-3)]<0&&a[n-(n-4)]<0&&a[n-(n-5)]<0&&a[n-(n-6)]<0&&a[n-(n-7)]<0&&a[n-(n-8)]<0&&a[n-(n-9)]<0){
				cout<<-(a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)]+a[n-(n-7)]+a[n-(n-8)]+a[n-(n-9)]);
			}else cout<<a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)]+a[n-(n-7)]+a[n-(n-8)]+a[n-(n-9)];
			 break;
		}
	}if(n==13){
		for(int i=1;i<=n;i++){
			if(a[n-(n-1)]<0&&a[n-(n-2)]<0&&a[n-(n-3)]<0&&a[n-(n-4)]<0&&a[n-(n-5)]<0&&a[n-(n-6)]<0&&a[n-(n-7)]<0&&a[n-(n-8)]<0&&a[n-(n-9)]<0&&a[n-(n-10)]<0){
				cout<<-(a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)]+a[n-(n-7)]+a[n-(n-8)]+a[n-(n-9)]+a[n-(n-10)]);
			}else cout<<a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)]+a[n-(n-7)]+a[n-(n-8)]+a[n-(n-9)]+a[n-(n-10)];
			 break;
		}
	}if(n==14){
		for(int i=1;i<=n;i++){
			if(a[n-(n-1)]<0&&a[n-(n-2)]<0&&a[n-(n-3)]<0&&a[n-(n-4)]<0&&a[n-(n-5)]<0&&a[n-(n-6)]<0&&a[n-(n-7)]<0&&a[n-(n-8)]<0&&a[n-(n-9)]<0&&a[n-(n-10)]<0&&a[n-(n-11)]<0){
				cout<<-(a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)]+a[n-(n-7)]+a[n-(n-8)]+a[n-(n-9)]+a[n-(n-10)]+a[n-(n-11)]);
			}else cout<<a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)]+a[n-(n-7)]+a[n-(n-8)]+a[n-(n-9)]+a[n-(n-10)]+a[n-(n-11)];
			 break;
		}
	}if(n==15){
		for(int i=1;i<=n;i++){
			if(a[n-(n-1)]<0&&a[n-(n-2)]<0&&a[n-(n-3)]<0&&a[n-(n-4)]<0&&a[n-(n-5)]<0&&a[n-(n-6)]<0&&a[n-(n-7)]<0&&a[n-(n-8)]<0&&a[n-(n-9)]<0&&a[n-(n-10)]<0&&a[n-(n-11)]<0&&a[n-(n-12)]<0){
				cout<<-(a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)]+a[n-(n-7)]+a[n-(n-8)]+a[n-(n-9)]+a[n-(n-10)]+a[n-(n-11)]+a[n-(n-12)]);
			}else cout<<a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)]+a[n-(n-7)]+a[n-(n-8)]+a[n-(n-9)]+a[n-(n-10)]+a[n-(n-11)]+a[n-(n-12)];
			 break;
		}
	}if(n==16){
		for(int i=1;i<=n;i++){
			if(a[n-(n-1)]<0&&a[n-(n-2)]<0&&a[n-(n-3)]<0&&a[n-(n-4)]<0&&a[n-(n-5)]<0&&a[n-(n-6)]<0&&a[n-(n-7)]<0&&a[n-(n-8)]<0&&a[n-(n-9)]<0&&a[n-(n-10)]<0&&a[n-(n-11)]<0&&a[n-(n-12)]<0&&a[n-(n-13)]<0){
				cout<<-(a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)]+a[n-(n-7)]+a[n-(n-8)]+a[n-(n-9)]+a[n-(n-10)]+a[n-(n-11)]+a[n-(n-12)]+a[n-(n-13)]);
			}else cout<<a[n-(n-1)]+a[n-(n-2)]+a[n-(n-3)]+a[n-(n-4)]+a[n-(n-5)]+a[n-(n-6)]+a[n-(n-7)]+a[n-(n-8)]+a[n-(n-9)]+a[n-(n-10)]+a[n-(n-11)]+a[n-(n-12)]+a[n-(n-13)];
			 break;
		}
	}
	freopen("crysatl.in","r",stdin);
	freopen("crysatl.out","w",stdout);
	return 0;
}

