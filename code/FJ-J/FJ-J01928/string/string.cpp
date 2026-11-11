#include<bits/stdc++.h>
using namespace std;
long long a[100006][5],n,l,j,sum=0,mi;
char d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>d;
		a[i][2]=d;
	}
	l=1;j=n;
	while(l<j){
		if(a[l][1]>a[j][1])mi=a[j][1];else mi=a[l][1];
			if(a[l][2]==a[j][2]){
			a[l][1]-=mi;
			a[j][1]-=mi;
			if(a[l][1]==0){
				l++;
			}
			if(a[j][1]==0){
				j--;
			}
			continue;
		}
		sum+=min(a[l][1],a[j][1]);
		a[l][1]-=mi;
		a[j][1]-=mi;
		
		if(a[l][1]==0){
				l++;
			}
		if(a[j][1]==0){
			j--;
		}//cout<<l<<" "<<j<<" "<<a[l][1]<<" "<<a[j][1]<<endl;
		//cout<<l<<j<<" "<<sum<<endl;
	}
	cout<<sum;
	
	
	
	return 0;
}
/*
9
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
1000000000 a
1000000000 a
1000000000 a


3
2 a
2 b
1 c






*/

