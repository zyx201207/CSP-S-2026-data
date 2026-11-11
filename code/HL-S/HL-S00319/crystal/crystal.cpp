#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    vector<long long> c(n);
    for(long long i=0;i<n;i++){
        cin>>c[i];
    }
    sort(c.begin(),c.end());
    long long ptr=0;
    long long sum=0;bool found=false;
    long long delta=0;
    while(ptr!=n+1){
//    	cout<<ptr<<endl;
        if(ptr!=0) delta = c[ptr]-c[ptr-1];
        else{
        	ptr++;
        	continue;
		}
        sum+=ptr*delta;
//        cout<<ptr<<":"<<sum<<endl;
        if(sum==m&&c[ptr+1]!=c[ptr]){
//        	cout<<"nowptr="<<ptr<<endl;
            cout<<ptr+1;
            found=true;
            break;
        }else if(sum>m&&ptr!=1){
//        	cout<<"nowsum="<<sum<<",ptr="<<ptr<<endl;
            cout<<ptr;
            found=true;
            break;
        }
        ptr++;
    }
    if(!found) cout<<1;
    return 0;
}


/*
¹ö¶¯Ç°×º
5 8
-3 -1 2 2 7


5 5 1 2 4 8 9

0 -2 -5 -5 -10
2 0 -3 -3 -8
5 3 0 0 -5
5 3 0 0 -5
10 8 5 5 0
 
 
 5 6 -10 3 5 7 14
*/
