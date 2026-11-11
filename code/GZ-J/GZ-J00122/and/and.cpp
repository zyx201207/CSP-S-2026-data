// GZ-J00122 贵阳市云岩区中天中学 朱腾予

#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,a[10000],s=0;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	
	if(m==1){
		for(int i=0;i<n;i++) s=max(s,a[i]);
	}else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j) continue;
				s=max(s,a[i]&a[j]);
			}
		}
	}else if(m==3){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					if(i==j||i==k||j==k) continue;
					s=max(s,a[i]&a[j]&a[k]);
				}
			}
		}
	}else if(m==4){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					for(int w=0;w<n;w++){
						if(i==j||i==k||j==k||w==i||w==j||w==k) continue;
						s=max(s,a[i]&a[j]&a[k]&a[w]);
					}
				}
			}
		}
	}else if(m==n){
		s=a[0];
		for(int i=1;i<n;i++) s=s&a[i];
	}else{
		s=511;
	}
	
	cout << s;
	
	return 0;
}
