#include<iostream>
using namespace std;
int n;
long long sum,ans1,ans2;
long long a[200005];
string c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	string s1=s;
	if(sum%2==1){
		int l=sum/2-1,r=(sum+1)/2;
		while(l!=-1){
			if(s[l]!=s[r]){
				s[r]=s[l],ans2++;
			}
			l--,r++;
		}
		l=sum/2-1,r=(sum+1)/2;
		while(l!=-1){
			if(s1[l]!=s1[r]){
				s1[l]=s1[r],ans1++;
			}
			l--,r++;
		}
		cout<<min(ans1,ans2);
	}
	else {
		int l=sum/2-1,r=sum/2;
		while(l!=-1){
			if(s[l]!=s[r]){
				s[l]=s[r],ans1++;
			}
			l--,r++;
		}
		l=sum/2-1,r=(sum+1)/2;
		while(l!=-1){
			if(s1[l]!=s1[r]){
				s1[r]=s1[l],ans2++;
			}
			l--,r++;
		}
		cout<<min(ans1,ans2);
	}
	return 0;
}
