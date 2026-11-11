#include<iostream>
#include<vector>

using namespace std;

int main(){

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<int>pm(m,0);
    for(int i=0;i<m;i++){
        cin>>pm[i];
    }
    vector<int>pt(0);
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        for(int j=0;j<2*k;j++){
            int f;
            cin>>f;
            pt.push_back(f);
        }
    }

    while(q--){
        int x,y;
        cin>>x>>y;
    }



    return 0;
}
