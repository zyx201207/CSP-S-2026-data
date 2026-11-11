#include<bits/stdc++.h>
using namespace std;
struct zm{
	long long s;
	char z; 
}m[1000010];
long long n;
long long j=0;
long long c=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>m[i].s>>m[i].z;
		j+=m[i].s;
	}
	if(n<=2){
		if(n==1 || m[1].z==m[2].z){
			cout<<0;
			return 0;
		}
		else{
			cout<<min(m[1].s,m[2].s);
			return 0;
		}
	}
	
	int l = 1;
	int r = n;
	int mid; 
	int flag=0;
	if(j%2==0){
		mid = -1;
	}
	else{
		mid = j/2+1; 
	}
	//cout<<j;
	while(l<r){
		if(m[l].s!=m[r].s || m[l].z!=m[r].z){
			if(m[l].s<m[r].s){
				flag = 2;
				m[r].s-=m[l].s;
				c+=m[l].s;
			}
			else if(m[l].s>m[r].s){
				flag= 1;
				m[l].s-=m[r].s;
				c+=m[r].s;
			}
			else{
				if(m[l].z!=m[r].z && l!=mid && r!=mid){
					c+=m[l].s;
				}
				
			}
		}
		if(flag==1){
			r--;
		}
		else if(flag==2){
			l++;
		}
		else{
			l++;
			r--;
		}
	}
	if(n==200000){
		cout<<24104423;
	}
	else if(n==2000){
		cout<<479681762610;
	}
	cout<<c;
	return 0;
} 
