#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[214514],la[214514],ra[214514],dra[214514];
char c[214514],lc[214514],rc[214514],drc[214514];

int ln=0,rn=0;

ll cuts[214514];
int cutn=0;

ll qla[214514],qra[214514];
char qlc[214514],qrc[214514];
int qln=0,qrn=0;

ll cnt=0;

int main(){
    fstream fi,fo;
    fi.open("string.in");fo.open("string.out");

    int n;
    fi>>n;
    for(int i=0;i<n;i++){
        fi>>a[i]>>c[i];
        cnt+=a[i];
    }

    //切割
    ll mid=cnt/2;
    ll cur=0;
    int i=0;
    //左侧
    for(;i<n;i++){
        if(cur+a[i]<=mid){
            la[ln]=a[i];
            lc[ln]=c[i];
            ln++;
            cur+=a[i];
        }else break;
    }
    //中间
    la[ln]=mid-cur;
    lc[ln]=c[i];
    ln++;
    if(cnt%2==1){
        mid++;
    }
    ra[rn]=(cur+a[i])-mid;
    rc[rn]=c[i];
    rn++;
    i++;

    //右侧
    for(;i<n;i++){
        ra[rn]=a[i];
        rc[rn]=c[i];
        cur+=a[i];
        rn++;
    }
    //右侧倒序
    for(int i=0;i<rn;i++){
        dra[i]=ra[rn-i-1];
        drc[i]=rc[rn-i-1];
    }
     //cout<<"l:"<<endl;
    //for(int i=0;i<ln;i++){
    //    cout<<la[i]<<" "<<lc[i]<<endl;
    //}
    //cout<<"r:"<<endl;
    //for(int i=0;i<rn;i++){
    //    cout<<dra[i]<<" "<<drc[i]<<endl;
    //}

    //切块
    cur=0;for(int i=0;i<ln;i++)cuts[cutn++]=(cur+=la[i]);
    cur=0;for(int i=0;i<rn;i++){
        //cout<<"q"<<cur<<" "<<dra[i]<<endl;
        cuts[cutn++]=(cur+dra[i]);
        cur+=dra[i];
    }
    sort(cuts,cuts+cutn);
    cur=0;
    int j=0;
    //cout<<"t1"<<endl;
    for(int i=0;i<ln;i++){
        //cout<<"cur="<<cur<<" 处理"<<i<<":"<<la[i]<<endl;
        for(;j<cutn;j++){
            if(cur>cuts[j])continue;
            if(cur+la[i]<=cuts[j])break;
            //if(cur<=cuts[j]&&cuts[j]<cur+la[i]){
                qla[qln]=cuts[j]-cur;
                if(qla[qln]==0)continue;
                qlc[qln]=lc[i];
                //cout<<" add:"<<qla[qln]<<" "<<qlc[qln]<<endl;
                cur+=qla[qln];la[i]-=qla[qln];
                qln++;
            //}
        }
        qla[qln]=la[i];
        if(qla[qln]==0)continue;
        qlc[qln]=lc[i];
        //cout<<" add(end):"<<qla[qln]<<" "<<qlc[qln]<<endl;
        qln++;
        cur+=la[i];
    }
    cur=0;
    j=0;
    for(int i=0;i<rn;i++){
        //cout<<"cur="<<cur<<" 处理"<<i<<":"<<ra[i]<<endl;
        for(;j<cutn;j++){
            if(cur>cuts[j])continue;
            if(cur+dra[i]<=cuts[j])break;
            //if(cur<=cuts[j]&&cuts[j]<cur+dra[i]){
                //cout<<" cut:"<<cuts[j]<<endl;
                qra[qrn]=cuts[j]-cur;
                if(qra[qrn]==0)continue;
                qrc[qrn]=drc[i];
                //cout<<" add:"<<qra[qrn]<<" "<<qrc[qrn]<<"(qrn="<<qrn<<")"<<endl;
                cur+=qra[qrn];dra[i]-=qra[qrn];
                qrn++;
            //}
        }
        qra[qrn]=dra[i];
        if(qra[qrn]==0)continue;
        qrc[qrn]=drc[i];
//cout<<" add(end):"<<qra[qrn]<<" "<<qrc[qrn]<<"(qrn="<<qrn<<")"<<endl;
        qrn++;
        cur+=dra[i];
    }


    //cout<<"l:"<<endl;
    //for(int i=0;i<qln;i++){
    //    cout<<qla[i]<<" "<<qlc[i]<<endl;
    //}
    //cout<<"r:"<<endl;
    //for(int i=0;i<qrn;i++){
     //   cout<<qra[i]<<" "<<qrc[i]<<endl;
    //}


//cout<<"cuts:";for(int i=0;i<cutn;i++)cout<<cuts[i]<<" ";cout<<endl;
    //cout<<"cutn="<<cutn<<" ln="<<ln<<" rn="<<rn<<endl;

    ll r=0;
    ll cl=0,cr=0;
    for(int i=0;i<qln;i++)cl+=qla[i];
    for(int i=0;i<qrn;i++)cr+=qra[i];
    for(int i=0;i<qln;i++){
        if(qlc[i]!=qrc[i])r+=qla[i];
        //if(qla[i]!=qra[i])cout<<"err: i="<<i<<" qla[i]="<<qla[i]<<" qra[i]="<<qra[i]<<endl;
    }
    fo<<r;
    //cout<<qln<<" "<<qrn<<endl;
    //cout<<cl<<" "<<cr<<endl;

    return 0;
}
