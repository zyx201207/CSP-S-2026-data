#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10;

int n;
struct Node{
	int sum;
	char c;
}s[N];


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	long long len=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].sum>>s[i].c;
		len+=s[i].sum;
	}
	
	long long res=0;
	Node l={0,' '},r={0,' '};
	int i=1,j=n;
	long long st=0,ed=0;
	while(j>i){
		if(j<i){
			break;
		}
		if(st==ed && j-i-1==1){
			break;
		}
//		cout<<i<<" "<<j<<" --- ";
		if(l.sum==0 && r.sum==0){
			
			if(s[i].sum>s[j].sum){
				l.sum=s[i].sum-s[j].sum;
				if(s[i].c==s[j].c){
					l.c=s[i].c;
					ed+=s[j].sum;
					j--;
				}else{
					res+=s[j].sum;
					l.c=s[i].c;
					ed+=s[j].sum;
					j--;
				}
			}else if(s[i].sum<s[j].sum){
				r.sum=s[j].sum-s[i].sum;
				if(s[i].c==s[j].c){
					r.c=s[j].c;
					st+=s[i].sum;
					i++;
				}else{
					res+=s[i].sum;
					r.c=s[j].c;
					st+=s[i].sum;
					i++;
				}
			}else{
				if(s[i].c==s[j].c){
					ed+=s[j].sum;
					st+=s[i].sum;
					i++,j--;
				}else{
					res+=s[i].sum;
					ed+=s[j].sum;
					st+=s[i].sum;
					i++,j--;
				}
			}
		}else if(l.sum>0){
			if(l.c==s[j].c){
				if(l.sum>s[j].sum){
					l.sum-=s[j].sum;
					ed+=s[j].sum;
					j--;
				}else{
					r.sum=s[j].sum-l.sum;
					l.sum=0;
					l.c=' '; 
					r.c=s[j].c;
					if(r.sum==0){
						r.c=' ';
					}
					st+=s[i].sum;
					i++;
				}
			}else{
				if(l.sum>s[j].sum){
					l.sum-=s[j].sum;
					res+=s[j].sum;
					ed+=s[j].sum;
					j--;
				}else{
					res+=l.sum;
					r.sum=s[j].sum-l.sum;
					l.sum=0;
					l.c=' ';
					r.c=s[j].c;
					if(r.sum==0){
						r.c=' ';
					}
					st+=s[i].sum;
					i++;
				}
			}
		}else{
			if(r.c==s[i].c){
				if(r.sum>s[i].sum){
					r.sum-=s[i].sum;
					st+=s[i].sum;
					i++;
				}else{
					l.sum=s[i].sum-r.sum;
					r.sum=0;
					r.c=' ';
					l.c=s[i].c;
					if(l.sum==0){
						l.c=' ';
					}
					ed+=s[j].sum;
					j--;
				}
			}else{
				if(r.sum>s[i].sum){
					r.sum-=s[i].sum;
					res+=s[i].sum;
					st+=s[i].sum;
					i++;
				}else{
					res+=r.sum;
					l.sum=s[i].sum-r.sum;
					r.sum=0;
					r.c=' ';
					l.c=s[i].c;
					if(l.sum==0){
						l.c=' ';
					}
					ed+=s[j].sum;
					j--;
				}
			}
		}
//		cout<<l.sum<<" "<<l.c<<" "<<r.sum<<" "<<r.c<<" "<<st<<" "<<ed<<endl;
		
	}
	cout<<res<<"\n";
	
	return 0;
} 
