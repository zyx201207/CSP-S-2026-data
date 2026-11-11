#include<bits/stdc++.h>
using namespace std;
bool check(int mid){

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    //er fen da an
    int l=1,r=1e9;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)) l=mid+1;
        else r=mid-1; 
    }
}