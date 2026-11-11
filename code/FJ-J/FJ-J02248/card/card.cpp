#include<bits/stdc++.h>
using namespace std;
long long t[500001],win[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n+1];
	a[0]=0;
	if(n>500||m>200){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			win[a[i]]++;
		}
		for(int i=2;i<=m;i++){
			win[i]+=win[i-1];
		}
		for(int i=1;i<=m;i++){
			cout<<win[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s=1;
		for(int j=i;j<=n;j++){
//			cout<<a[j]<<' ';
			if(t[a[j]]!=0){
				for(int f=1;f<=m;f++){
					if(t[f]>t[a[j]]){
						t[f]=0;
					}
				}
				s=t[a[j]]+1;
//				cout<<s;
			}else{
				t[a[j]]=s;
				s++;
//				cout<<s;
			}
//			for(int f=1;f<=m;f++){
//				cout<<t[m]<<' ';
//			}
//			cout<<endl;
		}
//		cout<<"-----\n";
		for(int j=1;j<=m;j++){
			if(t[j]!=0){
				win[j]++;
				t[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<win[i]<<' ';
	}
	return 0;
}
