#include<bits/stdc++.h>
using namespace std;
long long n,cnt,rcnt,lcnt;

long long a[20005];
char b[20005];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	
	}
	//a:4 1 3 1
	//b:a b a b
	/*for(int i=1;i<=8;i++){
		cout<<b[i]<<" ";
	
	}*/
	long long l=1,r=n;

		while(l<r){
		if(b[l]!=b[r]){
			//cout<<b[l]<<" "<<b[r];
		
			if(a[l]<a[r]){
				b[l]=b[r];
				cnt+=a[l];
			}
			else if(a[l]>a[r]){
				b[r]=b[l];
				cnt+=a[r];
			}
			else if(a[l]==a[r]){
				b[r]=b[l];
				cnt+=a[r];
			}
			if(b[r]==b[r-1]&&b[l]==b[l+1]){
				
				while(b[r]==b[r-1]){
					r--;
					rcnt++;
				}
				while(b[l]==b[l+1]){
					l++;
					lcnt++;
				}
			}
			
		}
		
		//cout<<cnt<<" "<<l<<" "<<r<<"\n";
		l++;
		r--;
	}
	if(n%2!=0){
			while(l<r){
			if(b[l]!=b[r]){
			//cout<<b[l]<<" "<<b[r];
		
				if(a[l]<a[r]){
					//a[l].p=a[r].p;
					cnt+=a[r];
				}
				else if(a[l]>a[r]){
					//a[r].p=a[l].p;
					cnt+=a[l];
				}
				else if(a[l]==a[r]){
					//a[r].p=a[l].p;
				cnt+=a[r];
			}
			else{
			
			}
		}
		 
		l++;
		r--;
		}
	}
	cnt+=max(rcnt,lcnt)-min(rcnt,lcnt);
	
	

	
	cout<<cnt;
	return 0;
}
