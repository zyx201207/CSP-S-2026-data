#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long l;
	char c;
}a1[100005],a2[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s1,s2;
	long long k=0,ans=0;
	long long cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a1[i].l>>a1[i].c;
		k+=a1[i].l;
	}
	if(k%2!=0){
		for(int i=1;i<=n;i++){
			ans+=a1[i].l;
			if(ans==k/2+1){
				a1[i].l--;
				s1=i;
				for(int j=1;j<=n;j++){
					a2[j].l=a1[j+i].l;
					a2[j].c=a1[j+i].c;
					if(a1[s1+j+1].l==0){
						s2=j;
						break;
					}
				}
				break;
			}else if(ans>k/2+1){
				a2[1].l=ans-k/2-1;
				a2[1].c=a1[i].c;
				a1[i].l-=a2[1].l;
				s1=i-1;
				for(int j=2;j<=n;j++){
					a2[j].l=a1[j+s1].l;
					a2[j].c=a1[j+s1].c;
					if(a1[s1+j].l==0){
						s2=j-1;
						break;
					}
				}
				break;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			ans+=a1[i].l;
			if(ans==k/2){
				s1=i;
				for(int j=1;j<=n;j++){
					a2[j].l=a1[j+i].l;
					a2[j].c=a1[j+i].c;
					if(a1[s1+j+1].l==0){
						s2=j;
						break;
					}
				}
				break;
			}else if(ans>k/2){
				a2[1].l=ans-k/2;
				a2[1].c=a1[i].c;
				a1[i].l-=a2[1].l;
				s1=i;
				for(int j=2;j<=n;j++){
					a2[j].l=a1[j+i-1].l;
					a2[j].c=a1[j+i-1].c;
					if(a1[i+j-1].l==0){
						s2=j-1;
						break;
					}
				}
				break;
			}
		}
	}
	long long i=1,j=1;
	while(i!=s1+1&&j!=s2+1){
		if(a1[i].c!=a2[j].c){
			if(a1[i].l>a2[j].l){
				cnt+=a1[i].l-a2[j].l;
				a1[i].l-=a2[j].l;
				j++;
			}else if(a1[i].l<a2[j].l){
				cnt+=a2[j].l-a1[i].l;
				a2[j].l-=a1[i].l;
				i++;
			}else{
				cnt+=a1[i].l;
				i++,j++;
			}
		}else{
			if(a1[i].l>a2[j].l){
				a1[i].l-=a2[j].l;
				j++;
			}else if(a1[i].l<a2[j].l){
				a2[j].l-=a1[i].l;
				i++;
			}else{
				i++,j++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
