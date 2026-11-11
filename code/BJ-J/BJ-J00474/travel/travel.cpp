#include<cstdio>


struct node{
    int chexiang;
    int pai;
    char lie;
};

int abs(int _x){
    return _x >= 0 ? _x : - _x;
}

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w",stdout);
    node c,s;
    scanf("%d %d%c %d %d%c\n", &c.chexiang, &c.pai, &c.lie, &s.chexiang, &s.pai, &s.lie);
    //printf("%d %d%c %d %d%c\n", c.chexiang, c.pai, c.lie, s.chexiang, s.pai, s.lie);
    bool ans[4] = {
        c.chexiang == s.chexiang,
        c.chexiang == s.chexiang && c.pai == s.pai,
        c.chexiang == s.chexiang && c.pai == s.pai && ((c.lie >= 'D' ) == ( s.lie >= 'D')),
        0
    };
    ans[3] = ans[2] && abs((int)(c.lie - s.lie)) == 1;
    for(int i = 0; i < 4; i++){
        printf("%d",ans[i]);
    }
    putchar('\n');
    return 0;
}