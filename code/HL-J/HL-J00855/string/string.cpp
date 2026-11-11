#include<bits/stdc++.h>
using namespace std;

int n1[100005]/*[100005]*/,n3[100005];
string n2/*[100005][100005]*/;
int main(){
	freopen("string.in","r",stdin);//2
	freopen("string.out","w",stdout);//2
	int n,i1=0,i2=0;cin>>n;char c;string a;
	long long d=0,p=0,b=0;
	for(int i=0;i<n;i++){
		cin>>b>>c;
		n1[i]=b;n2+=c;n3[i]=b;p+=b;
		
//		cout<<"b c n1 n2 n3 "<<b<<" "<<c<<" "<<n1[i]<<" "<<n2[i]<<" "<<n3[i]<<endl;//1
		
	}
	for(int i=0;i<n;i++){
		
//		cout<<"n3[i1] n3[n-1-i2] n-1-i2    "<<n3[i1]<<"   "<<n3[n-1-i2]<<"   "<<n-1-i2<<endl;//1
		
		if(n3[i1]>n3[n-1-i2]){
			/*
			cout<<"first"<<" n3[i1] n3[n-1-i2] n3[i1]-=n3[n-1-i2] i2 d  ";//1
			cout<<n3[i1];cout<<" "<<n3[n-1-i2]<<" ";//1
			cout<<n3[i1]-n3[n-1-i2]<<" ";//1
			cout<<i2<<" "<<d<<endl;//1
			//*/
			n3[i1]-=n3[n-1-i2];
			if(n2[i1]!=n2[n-1-i2]){
				d+=n3[n-1-i2];
			}
			n3[n-1-i2]=0;i2++;
			/*
			cout<<"end  "<<" n3[i1] n3[n-1-i2] n3[i1]-=n3[n-1-i2] i2 d  ";//1
			cout<<n3[i1];cout<<" "<<n3[n-1-i2]<<" ";//1
			cout<<n3[i1]-n3[n-1-i2]<<" ";//1
			cout<<i2<<" "<<d<<endl;//1
			//*/
		}
		else if(n3[i1]<=n3[n-1-i2]){
			/*
			cout<<"first"<<" n3[i1] n3[n-1-i2] n3[n-1-i2]-=n3[i1] i1 d  ";//1
			cout<<n3[i1];cout<<" "<<n3[n-1-i2]<<" ";//1
			cout<<n3[n-1-i2]-n3[i1]<<" ";//1
			cout<<i1<<" "<<d<<endl;//1
			//*/
			n3[n-1-i2]-=n3[i1];
			if(n2[i1]!=n2[n-1-i2]){
				d+=n3[i1];
			}
			n3[i1]=0;i1++;
			/*
			cout<<"end  "<<" n3[i1] n3[n-1-i2] n3[n-1-i2]-=n3[i1] i1 d  ";//1
			cout<<n3[i1];cout<<" "<<n3[n-1-i2]<<" ";//1
			cout<<n3[n-1-i2]-n3[i1]<<" ";//1
			cout<<i1<<" "<<d<<endl;//1
			//*/
		}
	}
	cout<<d;
	return 0;
}