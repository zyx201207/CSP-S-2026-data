#include<bits/stdc++.h>
using namespace std;
struct numb{
	int num;
	char con;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0;
	int n;
	cin>>n;
	vector<numb> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].num;
		cin>>a[i].con;
	}
	int l1=1,r1=n,l2=1,r2=a[n-1].num;
	while(l1<r1){
		if(a[l1-1].con!=a[r1-1].con){
			if(a[l1-1].num-l2+1<r2){
				ans+=a[l1-1].num-l2+1;
				r2-=a[l1-1].num-l2+1;
				l1++;
				l2=1;
			}else if(a[l1-1].num-l2+1>r2){
				ans+=r2;
				l2+=r2;
				r1--;
				r2=a[r1-1].num;
			}else {
				ans+=r2;
				l1++;
				r1--;
				l2=1;
				r2=a[r1-1].num;
			}
		}else{
			if(a[l1-1].num-l2+1<r2){
				r2-=a[l1-1].num-l2+1;
				l1++;
				l2=1;
			}else if(a[l1-1].num-l2+1>r2){
				l2+=r2;
				r1--;
				r2=a[r1-1].num;
			}else {
				l1++;
				r1--;
				l2=1;
				r2=a[r1-1].num;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
