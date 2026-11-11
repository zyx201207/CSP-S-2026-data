#include<bits/stdc++.h>
using namespace std;
int n,m,a[5005];
int ans[5005];
int main(){
    freopen("and1.in","r",stdin);
    freopen("and.out","w",stdout);
    queue<int>s;
    cin>>n>>m;
    int temp;
    int pos;
    for(int kk=0;kk<n;kk++)cin>>a[kk];

    for(int i=0;i<n;i++){
        int a1[5005]={};
        for(int j=i;j<n;j++){
            a1[j]=a[j];
            temp=a1[j];
            bool f=binary_search(a1,a1+n,temp);
            //cout<<"debug:f,temp"<<f<<" "<<temp<<endl;
            if(!f)s.push(temp);
            else if(f){
                    pos=lower_bound(a1,a1+n,temp)-a1+1;
                    //cout<<"debug:pos"<<pos<<endl;
                for(int k=pos;k<j+1;k++){
					//cout<<"debug:k"<<k<<endl;
					s.pop();
					
                    }
                    s.push(temp);
            }
        }
        while(!s.empty()){
                ans[s.front()-1]++;
                s.pop();
            }
    }
    for(int i=0;i<m;i++)cout<<ans[i];
return 0;}
