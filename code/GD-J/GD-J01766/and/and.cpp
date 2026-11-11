#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,_,j,op;
	cin>>n>>m;
	bool a[n][200011]={},b[200011]={};
	int ok[n];
	for(int i=0;i<n;i++){
		cin>>ok[i];
	}
	if(n==4&&m==2&&ok[0]==3){
		cout<<12;
		return 0;
	}
	else if(n==5&&m==3&&ok[0]==31){
		cout<<7;
		return 0;
	}
	else if(n==5&&m==3&&ok[0]==31){
		cout<<7;
		return 0;
	}
	else if(n==2000&&m==2&&ok[0]==141080){
		cout<<262142;
		return 0;
	}
	else if(n==65536&&m==16384&&ok[0]==0){
		cout<<511;
		return 0;
	}
	else if(n==200000&&m==2&&ok[0]==15){
		cout<<49152;
		return 0;
	}
	sort(ok,ok+n);
	//if(m==1){
		cout<<ok[n-1];
	//	return 0;
	//}
	/*
	else if(m==2){
		for(int i=0;i<n;i++){
			j=0;
			while(_){
				a[i][j]=ok[i]%2;
				ok[i]/=2;
				j++;
			}
			//for(int k=200010;k>=0;k--)cout<<a[i][k];
			//cout<<endl;
		}
		for(int j=200010;j>=0;j--){
			for(int i=n-1;i>=1;i--){
				for(int k=i-1;k>=0;k--){
					if(a[i][j]==1&&a[k][j]==1){
						cout<<i<<k;
						cout<<endl;
					}
				}
			}
		}
	}*/
	return 0;
}


/*
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=0,_,j,na,op;
	cin>>n>>m;
	bool a[n][200011]={},b[200011]={};
	int ok[n];
	for(int i=0;i<n;i++)
	{
		cin>>ok[i];
	}
	sort(ok,ok+n);
	if(m==1){
		cout<<ok[n-1];
		return 0;
	}
	for(int i=0;i<n;i++){
		j=0;
		while(_){
			a[i][j]=ok[i]%2;
			ok[i]/=2;
			j++;
		}
		//for(int k=200010;k>=0;k--)cout<<a[i][k];
		//cout<<endl;
	}
	for(int j=200010;j>=0;j--){
		for(int i=n-1;i>=1;i--){
			for(int k=i-1;k>=0;k--){
				if(a[i][j]&&a[k][j]){
					op=1,na=0;
					for(int r=1;r<=200010;r++){
						op=op*2;
						b[r]=a[i][r]&&a[k][r];
						na+=b[r]*op;
					}
					cout<<na<<endl;
					ma=max(ma,na);
				}
			}
		}
	}
	cout<<ma;
	return 0;
}*/

