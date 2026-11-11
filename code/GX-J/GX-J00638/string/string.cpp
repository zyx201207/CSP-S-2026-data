#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+9;
int t[mx];
string l1[mx];
int main(){
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    long long n,l=0,r,c=0;
    //long b1;//,b2;
    cin>>n;
    r=n-1;
    for(int i=0;i<n;i++){
        cin>>t[i]>>l1[i];//cout<<t[i]<<l1[i]<<i<<' ';
    }
    while(l<r){
        if(l1[l]==l1[r] or 0<5){//cout<<'a';
            if(t[l]>t[r]){//cout<<t[l]<<' '<<t[r]<<r<<endl;
                t[l]-=t[r];
                if(l1[l]!=l1[r]){//cout<<'a';
					c+=t[r];
				}
                r--;
                //b1=t[l]-t[r];
                //b2=l1[l];
            }
            else if(t[l]<t[r]){//cout<<'w';
				t[r]-=t[l];
				if(l1[l]!=l1[r]){//cout<<'a';
					c+=t[l];
				}
				l++;
				
				//b1=t[r]-t[l];
				//b2=l1[r];
			}
			else{//cout<<'e';
				if(l1[l]!=l1[r]){//cout<<'a';
					c+=t[l];
				}
				l++;
				r--;
			}
        }
        //else{}
    }
    cout<<c;
    return 0;
    }
